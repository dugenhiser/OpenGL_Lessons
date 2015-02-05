function Renderer(canvas, gl) {
    this.canvas = canvas;
    this.gl = gl;
    this.aspectRatio = 0;
    this.fieldOfView = 70;
    this.screenSize = new vec2();
    this.reshape(canvas.width, canvas.height);

    gl.clearColor(0,0,0,1);
    gl.enable(gl.DEPTH_TEST);
    gl.enable(gl.CULL_FACE);

    this.initLightShader(gl);
    this.initDragon(gl);
    this.bindObjectToLightShader(gl);
    this.objectRotation = 0;
}

Renderer.prototype.initLightShader = function(gl) {
    this.shaderProgramID = getShaderProgram(gl, "light_v", "light_f");
    gl.useProgram(this.shaderProgramID);

    this.vertexAttributeID = gl.getAttribLocation(this.shaderProgramID, "vertex");
    this.normalAttributeID = gl.getAttribLocation(this.shaderProgramID, "normal");

    this.mvpID = gl.getUniformLocation(this.shaderProgramID, "mvp");
    this.normalMatrixID = gl.getUniformLocation(this.shaderProgramID, "normalMatrix");

    gl.enableVertexAttribArray(0);
    gl.enableVertexAttribArray(1);
};

Renderer.prototype.initDragon = function(gl) {
    this.vbo = gl.createBuffer();
    this.nbo = gl.createBuffer();
    this.mesh = {};
    this.mesh.numVertices = 0;
    loadOBJFile(gl, "dragon.obj", this.mesh, this.vbo, this.nbo);
};

Renderer.prototype.bindObjectToLightShader = function(gl) {
    gl.bindBuffer(gl.ARRAY_BUFFER, this.vbo);
    gl.vertexAttribPointer(this.vertexAttributeID, 3, gl.FLOAT, false, 0, 0);

    gl.bindBuffer(gl.ARRAY_BUFFER, this.nbo);
    gl.vertexAttribPointer(this.normalAttributeID, 3, gl.FLOAT, false, 0, 0);
};

Renderer.prototype.reshape = function(w, h) {
    this.screenSize.x = w;
    this.screenSize.y = h;
    this.aspectRatio = w / h;
    this.gl.viewport(0, 0, w, h);
    this.perspectiveMatrix = perspectiveAspect(this.aspectRatio, this.fieldOfView, 0.1, 5000.0);
};

Renderer.prototype.update = function() {
    this.objectRotation += .25;
    if (this.objectRotation > 360)
        this.objectRotation -= 360;
};

Renderer.prototype.draw = function(gl) {
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    
    var viewMatrix = translate(0,0,-100);
  	var mv = mat4_x_mat4_chain(
        	viewMatrix,
        	translate(0,-15,0),
        	scale(7,7,7),
        	rotateY(this.objectRotation));
    var mvp = mat4_x_mat4(this.perspectiveMatrix, mv);
    var normalMatrix = mat4ToMat3(mv);
    var normalMatrixTranspose = mat3Transpose(normalMatrix);
    gl.uniformMatrix3fv(this.normalMatrixID, false, new Float32Array(normalMatrixTranspose));
    this.numVertices = this.mesh.numVertices;
    var mvpTranspose = mat4Transpose(mvp);
    gl.uniformMatrix4fv(this.mvpID, false, new Float32Array(mvpTranspose));
    gl.drawArrays(gl.TRIANGLES, 0, this.numVertices);

    gl.flush();
};


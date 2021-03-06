function Renderer(canvas, gl) {
    this.canvas = canvas;
    this.gl = gl;
    this.aspectRatio = 0;
    this.fieldOfView = 70;
    this.screenSize = new vec2();
    this.reshape(canvas.width, canvas.height);

    gl.clearColor(0,0,0,1);
    gl.enable(gl.DEPTH_TEST);

    this.initColorShader(gl);
    this.initTriangle(gl);
    this.bindObjectToColorShader(gl);
}

// Load shaders, get attribute locations, and get uniform locations
Renderer.prototype.initColorShader = function(gl) {
    // Shaders defined in index.html
    this.shaderProgramID = getShaderProgram(gl, "color_v", "color_f");
    gl.useProgram(this.shaderProgramID);

    this.vertexAttributeID = gl.getAttribLocation(this.shaderProgramID, "vertex");
    this.colorAttributeID  = gl.getAttribLocation(this.shaderProgramID, "color");

    this.mvpID = gl.getUniformLocation(this.shaderProgramID, "mvp");

    gl.enableVertexAttribArray(0);
    gl.enableVertexAttribArray(1);
};

Renderer.prototype.initTriangle = function(gl) {
    // TODO: make a triangle
};

Renderer.prototype.bindObjectToColorShader = function(gl) {
    gl.bindBuffer(gl.ARRAY_BUFFER, this.vbo);
    gl.vertexAttribPointer(this.vertexAttributeID, 3, gl.FLOAT, false, 0, 0);

    gl.bindBuffer(gl.ARRAY_BUFFER, this.cbo);
    gl.vertexAttribPointer(this.colorAttributeID, 4, gl.FLOAT, false, 0, 0);
};

Renderer.prototype.reshape = function(w, h) {
    this.screenSize.x = w;
    this.screenSize.y = h;
    this.aspectRatio = w / h;
    this.gl.viewport(0, 0, w, h);
    this.perspectiveMatrix = perspectiveAspect(this.aspectRatio, this.fieldOfView, 0.1, 5000.0);
};

Renderer.prototype.update = function() {
};

Renderer.prototype.draw = function(gl) {
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    // TODO: draw the triangle we made

    gl.flush();
};


#version 330

uniform mat4 ProjModelViewMatrix;
uniform mat4 ModelViewMatrix;

uniform mat4 NormalMatrix;

in vec3 Vertex;
in vec2 TexCoord;
in vec3 Normal;
in vec3 Tangent;

out vec2 texCoord;
out vec3 normal;
out vec3 position;
out vec3 tangent;
out mat3 normalMatrix;

//varying vec2 texCoord;
//attribute vec2 TexCoord;

void main(void)
{
    gl_Position = ProjModelViewMatrix * vec4(Vertex, 1.0);
    position = normalize(gl_Position.xyz);

    normal = normalize(mat3(NormalMatrix) * Normal);
    texCoord = TexCoord;
    tangent = mat3(NormalMatrix)*Tangent;
    normalMatrix = mat3(NormalMatrix);
}
#version 330 core
out vec4 FragColor;

in vec3 vertOut;

void main()
{
    FragColor = vec4(vertOut.x, vertOut.y, vertOut.z, 0.0f);
}
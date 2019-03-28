#version 330 core
out vec4 FragColor;

in vec3 vertOut;

void main()
{
    FragColor = vec4(vertOut, 1.0f);
}
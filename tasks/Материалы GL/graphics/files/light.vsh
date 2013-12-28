










varying vec3 N;
varying vec3 L;

void main(void)
{
   L = normalize(vec3(gl_LightSource[0].position));
   N = normalize(gl_NormalMatrix * gl_Normal);

   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
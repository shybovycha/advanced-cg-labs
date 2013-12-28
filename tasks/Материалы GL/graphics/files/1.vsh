
uniform float waveTime; 
uniform float waveHeight; 

void main() 
{ 
	vec4 v = gl_Vertex;
	// v.z = sin((v.x + v.y) + waveTime) * waveHeight; 
	gl_Position = gl_ModelViewProjectionMatrix * v;
}
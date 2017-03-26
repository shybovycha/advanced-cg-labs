
uniform float waveTime; 

void main() 
{ 
	float r = (sin(waveTime) + 1) / 2.0;
	gl_FragColor = gl_Color; // vec4( r, 0.0, 1 - r, 1.0);
}
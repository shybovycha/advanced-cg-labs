uniform sampler2D testTexture;
uniform sampler2D HeightTexture;
varying vec2 v_texCoord;

varying vec3 EyeDir;

void main( void )
{
    
    // This is the pride of the sample.
    // Essentially what this does is shift the
    // tex coords of the fragment closer towards the 'eye'
    // depending on the fragment's 'height'.
    // Note how the offset is scaled to 0.03 and has a bias
    // of -0.015.
    // This is simple and effective, but also remember
    // that on steep 'gradients' there will be artifacts.
    // This is, after all, only an approximation.

    vec3 EyeT = normalize(EyeDir);
    vec4 Offset = texture2D(HeightTexture,v_texCoord);
    Offset = Offset * 0.04 - 0.02;
    vec2 TexCoords = Offset.xy * EyeT.xy + v_texCoord;

    // This also works very well with Bump Mapping.
    // just remember to use the shifted tex coords when
    // getting the normal.

    gl_FragColor =texture2D( testTexture, TexCoords ); 

}

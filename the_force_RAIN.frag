float circ(vec2 p){
    return length(p) - .50;   
}

// http://www.iquilezles.org/www/articles/palettes/palettes.htm
// As t runs from 0 to 1 (our normalized palette index or domain), 
//the cosine oscilates c times with a phase of d. 
//The result is scaled and biased by a and b to meet the desired constrast and brightness.
vec3 cosPalette( float t, vec3 a, vec3 b, vec3 c, vec3 d )
{
    return a + b*cos( 6.28318*(c*t+d) );
}


void main()
{
    // distance metric
    vec2 position = uv();

    // create our shape! we scale position by 4 so the circle appears smaller
    float shape = circ( position * vec2(44444.0));
    
    // get our color add shape to time so the shape affect how the colors are chosen
    vec3 col = cosPalette(shape + time/20.,vec3(0.5),vec3(0.5),vec3(1),vec3(0,0,0));
    
    // shape is 1 when there is no shape and 0 when there is a shape so multiplying col by 
    // shape colors where shape is 1 aka where there is no shape!
     col = vec3(shape) * col;

    // output: pixel color
    gl_FragColor = min(vec4( col, 1.0 ), vec4(0.8));
    // we take the min of the output color and a very light grey color because The Force makes 
    // all of their controls white at the bottom all white without any sort of outline, which is 
    // silly, so you can make it vec4(col.rgb,1.0) in other softwares or if you dont care 
    // about seeing the controls
}
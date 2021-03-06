#include "standard.hpp"

const char *StandardShader::VERTEX =
" attribute vec3 position; "
" attribute vec3 normal; "
" attribute vec2 uv; "
" varying vec4 fragmentPosition; "
" varying vec3 fragmentNormal; "
" varying vec2 fragmentUV; "
" uniform mat4 projection; "
" uniform mat4 view; "
" uniform mat3 normalView; "
" void main() { "
"   fragmentUV = uv; "
"   fragmentNormal = normalView * normal; "
"   fragmentPosition = view * vec4(position, 1.0); "
"   gl_Position = projection * fragmentPosition; "
" } ";

const char *StandardShader::FRAGMENT =
" precision lowp float; "
" varying vec4 fragmentPosition; "
" varying vec3 fragmentNormal; "
" varying vec2 fragmentUV; "
" uniform sampler2D texture; "
" uniform vec4 fogColor; "
" uniform vec3 sunPosition; "
" const float LOG2 = 1.442695; "
" const float density = 0.03; "
" const float ambientFactor = 0.2; "
" void main() { "
"   float distance = length(fragmentPosition); "
"   float fogFactor = clamp(exp2(-density * density * distance * distance * LOG2), 0.0, 1.0); "
"   float lightFactor = max(dot(normalize(fragmentNormal), normalize(sunPosition)), ambientFactor);  "
"   gl_FragColor = mix(fogColor, texture2D(texture, fragmentUV) * lightFactor, fogFactor); "
" } ";

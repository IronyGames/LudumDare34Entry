#pragma once

#include <string>
typedef std::string String;

#include "cinder/gl/Texture.h"
typedef cinder::gl::Texture2dRef glImageRef;

#include "cinder/Vector.h"
typedef cinder::ivec2 Coords2Dint;
typedef cinder::dvec2 Coords2Ddouble;
typedef cinder::vec2 Coords2Dfloat;
typedef cinder::ivec3 Coords3Dint;
typedef cinder::dvec3 Coords3Ddouble;
typedef cinder::vec3 Coords3Dfloat;

#include "cinder/audio/Voice.h"
typedef cinder::audio::VoiceRef ciVoicePointer;

#include "cinder/Color.h"
typedef cinder::Color ciColor;

#include <map>
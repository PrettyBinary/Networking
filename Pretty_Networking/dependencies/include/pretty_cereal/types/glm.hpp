/*! \file glm.hpp
    \brief Support for types found in \<glm\>
    \ingroup STLSupport */
/*
  Copyright (c) 2014, Randolph Voorhies, Shane Grant
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of cereal nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL RANDOLPH VOORHIES OR SHANE GRANT BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef CEREAL_TYPES_GLM_HPP_
#define CEREAL_TYPES_GLM_HPP_

#include "cereal\cereal.hpp"
#include "glm\glm.hpp"

namespace cereal
{
  //! Serializing (save) for glm::ivec2
  template <class Archive> inline
  void CEREAL_SAVE_FUNCTION_NAME( Archive & ar, glm::ivec2 const & vec )
  {
	  ar(	CEREAL_NVP_("{ ivec2 } x, r, s", vec.x),
			CEREAL_NVP_("{ ivec2 } y, g, t", vec.y));
  }

  //! Serializing (load) for glm::ivec2
  template <class Archive> inline
  void CEREAL_LOAD_FUNCTION_NAME( Archive & ar, glm::ivec2 & vec )
  {
    ar(vec.x, vec.y);
  }

  //! Serializing (save) for glm::ivec3
  template <class Archive> inline
	  void CEREAL_SAVE_FUNCTION_NAME(Archive & ar, glm::ivec3 const & vec)
  {
	  ar(	CEREAL_NVP_("{ ivec3 } x, r, s", vec.x),
			CEREAL_NVP_("{ ivec3 } y, g, t", vec.y),
			CEREAL_NVP_("{ ivec3 } z, b, q", vec.z));
  }

  //! Serializing (load) for glm::ivec3
  template <class Archive> inline
	  void CEREAL_LOAD_FUNCTION_NAME(Archive & ar, glm::ivec3 & vec)
  {
	  ar(vec.x, vec.y, vec.z);
  }

  //! Serializing (save) for glm::ivec4
  template <class Archive> inline
	  void CEREAL_SAVE_FUNCTION_NAME(Archive & ar, glm::ivec4 const & vec)
  {
	  ar(	CEREAL_NVP_("{ ivec4 } x, r, s", vec.x),
			CEREAL_NVP_("{ ivec4 } y, g, t", vec.y),
			CEREAL_NVP_("{ ivec4 } z, b, q", vec.z),
			CEREAL_NVP_("{ ivec4 } w, a, p", vec.w));
  }

  //! Serializing (load) for glm::ivec4
  template <class Archive> inline
	  void CEREAL_LOAD_FUNCTION_NAME(Archive & ar, glm::ivec4 & vec)
  {
	  ar(vec.x, vec.y, vec.z, vec.w);
  }

  //! Serializing (save) for glm::vec2
  template <class Archive> inline
	  void CEREAL_SAVE_FUNCTION_NAME(Archive & ar, glm::vec2 const & vec)
  {
	  ar(	CEREAL_NVP_("{ vec2 } x, r, s", vec.x),
			CEREAL_NVP_("{ vec2 } y, g, t", vec.y));
  }

  //! Serializing (load) for glm::vec2
  template <class Archive> inline
	  void CEREAL_LOAD_FUNCTION_NAME(Archive & ar, glm::vec2 & vec)
  {
	  ar(vec.x, vec.y, vec.z);
  }


  //! Serializing (save) for glm::vec3
  template <class Archive> inline
	  void CEREAL_SAVE_FUNCTION_NAME(Archive & ar, glm::vec3 const & vec)
  {
	  ar(	CEREAL_NVP_("{ vec3 } x, r, s", vec.x),
			CEREAL_NVP_("{ vec3 } y, g, t", vec.y),
			CEREAL_NVP_("{ vec3 } z, b, q", vec.z));
  }

  //! Serializing (load) for glm::vec3
  template <class Archive> inline
	  void CEREAL_LOAD_FUNCTION_NAME(Archive & ar, glm::vec3 & vec)
  {
	  ar(vec.x, vec.y, vec.z);
  }


  //! Serializing (save) for glm::vec4
  template <class Archive> inline
	  void CEREAL_SAVE_FUNCTION_NAME(Archive & ar, glm::vec4 const & vec)
  {
	ar(	CEREAL_NVP_("{ vec4 } x, r, s", vec.x),
		CEREAL_NVP_("{ vec4 } y, g, t", vec.y),
		CEREAL_NVP_("{ vec4 } z, b, q", vec.z),
		CEREAL_NVP_("{ vec4 } w, a, p", vec.w));
  }

  //! Serializing (load) for glm::vec4
  template <class Archive> inline
	  void CEREAL_LOAD_FUNCTION_NAME(Archive & ar, glm::vec4 & vec)
  {
	  ar(vec.x, vec.y, vec.z, vec.w);
  }

} // namespace cereal

#endif // CEREAL_TYPES_GLM_HPP_

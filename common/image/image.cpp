// ======================================================================== //
// Copyright 2009-2013 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#include "image.h"
#include "sys/stl/string.h"

#include "freeimage.h"

#include <map>
#include <iostream>

namespace embree
{

	Ref<Image> load_freeImage(const FileName& fileName);

    //-------------------------------------------------------------
	//loads an image from a file with auto-detection of format
	//-------------------------------------------------------------

  Ref<Image> loadImageFromDisk(const FileName& fileName) try
  {
    std::string ext = std::strlwr(fileName.ext());


    if (ext == "ppm") return loadPPM(fileName);
    if (ext == "pfm") return loadPFM(fileName);

	return load_freeImage(fileName);
		
    throw std::runtime_error("image format " + ext + " not supported");

  }
  catch (const std::exception& e) {
    std::cout << "cannot read file " << fileName << ": " << e.what() << std::endl;
    return null;
  }


  //-------------------------------------------------------------
  // loads an image from a file with auto-detection of format 
  //-------------------------------------------------------------
  Ref<Image> loadImage(const FileName& fileName, bool cache)
  {
    static std::map<std::string,Ref<Image> > image_cache;

    if (!cache)
      return loadImageFromDisk(fileName);

    if (image_cache.find(fileName) == image_cache.end())
        image_cache[fileName] = loadImageFromDisk(fileName);

    return image_cache[fileName];
  }


  //-------------------------------------------------------------
  // NEU : Elmer 10.2014
  // load freeimage
  //-------------------------------------------------------------
  Ref<Image> load_freeImage(const FileName& fileName)
  {

	  FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(fileName.c_str(), 0);

	  FIBITMAP *dib(0);
	  BYTE*     pixels(0);

	  if (FreeImage_FIFSupportsReading(fif))
		  dib = FreeImage_Load(fif, fileName.c_str());

	  if (!dib)
		  return false;

	  pixels = FreeImage_GetBits(dib);
	  size_t breite = FreeImage_GetWidth(dib);
	  size_t hoehe = FreeImage_GetHeight(dib);

	  //if this somehow one of these failed (they shouldn't), return failure
	  if ((pixels == 0) || (breite == 0) || (hoehe == 0))
		  return false;

	  //Image* out = new ImageT<Col3f>(breite, hoehe, fileName);

	  /* create image and fill with data */
	  Ref<Image> out = new Image4c(breite , hoehe, fileName);


	  float rcpMaxRGB = 1.0f / float(255.0);

	  for (size_t y = 0; y<out->height; y++)
	  {

		  for (size_t x = 0; x<out->width; x++)
		  {
			  RGBQUAD value;

			  FreeImage_GetPixelColor(dib, x, y, &value);

			  Color4 c;
			  c.r = float(value.rgbRed)*rcpMaxRGB;
			  c.g = float(value.rgbGreen)*rcpMaxRGB;
			  c.b = float(value.rgbBlue)*rcpMaxRGB;
			  c.a = 1.0;

			  out->set(x, y, c);
		  }

	  }

	  return out;
  }


  //-------------------------------------------------------------
  // NEU : Elmer 10.2014
  // store freeimage
  //-------------------------------------------------------------
  void storeImage(const Ref<Image>& img, const FileName& fileName) try
  {
    std::string ext = strlwr(fileName.ext());

    if (ext == "ppm") { storePPM(img,fileName); return; }
    if (ext == "pfm") { storePFM(img,fileName); return; }
    if (ext == "tga") { storeTga(img,fileName); return; }


	//------------------------------------
	// freeimage store
	//------------------------------------
	FIBITMAP *dib = FreeImage_Allocate(img->width, img->height, 24);

	int bytespp = FreeImage_GetLine(dib) / FreeImage_GetWidth(dib);

	unsigned Hoehe = FreeImage_GetHeight(dib);

	for (unsigned y = 0 ; y < Hoehe ; y++ )
	{
		BYTE *bits = FreeImage_GetScanLine(dib, y);

		for (unsigned x = 0; x < FreeImage_GetWidth(dib); x++)
		{
			Color4 c = img->get(x, y);

			// Set pixel color to green with a transparency of 128
			bits[FI_RGBA_RED]   = clamp(c.r)*255.0f;
			bits[FI_RGBA_GREEN] = clamp(c.g)*255.0f;
			bits[FI_RGBA_BLUE]  = clamp(c.b)*255.0f;
			bits[FI_RGBA_ALPHA] = 255 ;

			// jump to next pixel
			bits += bytespp;
		}
	}

	FreeImage_FlipVertical(dib);
	
	if (FreeImage_Save(FIF_BMP, dib, fileName.c_str(), 0))
		return;

	FreeImage_Unload(dib);;


    throw std::runtime_error("image format " + ext + " not supported");
  }
  catch (const std::exception& e) {
    std::cout << "cannot write file " << fileName << ": " << e.what() << std::endl;
  }

  /*! template instantiations */
  template class ImageT<Col3c>;
  template class ImageT<Col3f>;
}

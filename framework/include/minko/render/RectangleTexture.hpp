/*
Copyright (c) 2014 Aerys

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "minko/Common.hpp"

#include "minko/render/AbstractTexture.hpp"

namespace minko
{
    namespace render
    {
        class RectangleTexture :
            public AbstractTexture
        {
        public:
            typedef std::shared_ptr<RectangleTexture>            Ptr;

        private:
            typedef std::shared_ptr<AbstractContext>    AbstractContextPtr;

        private:
            std::vector<unsigned char>                  _data;

        public:
            inline static
            Ptr
            create(AbstractContextPtr    context,
                   unsigned int          width,
                   unsigned int          height,
                   TextureFormat         format,
                   const std::string&    filename = "")
            {
                return std::shared_ptr<RectangleTexture>(
                    new RectangleTexture(
                        context,
                        width,
                        height,
                        format,
                        filename
                    )
                );
            }

            std::vector<unsigned char>&
            data()
            {
                return _data;
            }

            const std::vector<unsigned char>&
            data() const
            {
                return _data;
            }

            void
            data(unsigned char* data,
                 int            widthGPU    = -1,
                 int            heightGPU   = -1);

            void
            resize(int width, int height, bool resizeSmoothly);

            void
            dispose();

            void
            disposeData();

            void
            upload();

            ~RectangleTexture()
            {
                dispose();
            }

        private:
            RectangleTexture(AbstractContextPtr  context,
                             unsigned int        width,
                             unsigned int        height,
                             TextureFormat       format,
                             const std::string&  filename);
        };
    }
}

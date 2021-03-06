/*
 The MIT License (MIT)
 
 Copyright (c) 2013 Alexander Grebenyuk (github.com/kean).
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


@interface DFImageProcessing : NSObject

#pragma mark - Scaling

// Points
+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)size;
+ (UIImage *)imageWithImage:(UIImage *)image aspectFitSize:(CGSize)size;
+ (UIImage *)imageWithImage:(UIImage *)image aspectFillSize:(CGSize)size;

// Pixels
+ (UIImage *)imageWithImage:(UIImage *)image aspectFitPixelSize:(CGSize)size;
+ (UIImage *)imageWithImage:(UIImage *)image aspectFillPixelSize:(CGSize)size;

@end


#pragma mark - Intermediate Calculations

static inline CGSize DFPixelSizeFromSize(CGSize size) {
   CGFloat scale = [UIScreen mainScreen].scale;
   return CGSizeMake(size.width * scale, size.height * scale);
}


static inline CGSize DFSizeFromPixelSize(CGSize size) {
   CGFloat scale = [UIScreen mainScreen].scale;
   return CGSizeMake(size.width / scale, size.height / scale);
}


static inline CGSize DFImageSize(UIImage *image) {
   CGFloat scale = [UIScreen mainScreen].scale;
   if (image.scale == scale) {
      return image.size;
   } else {
      return CGSizeMake(image.size.width / scale, image.size.height / scale);
   }
}


static inline CGSize DFImageBitmapPixelSize(UIImage *image) {
   return CGSizeMake(CGImageGetWidth(image.CGImage), CGImageGetHeight(image.CGImage));
}


static inline CGSize DFImagePixelSize(UIImage *image) {
   return CGSizeMake(image.size.width * image.scale, image.size.height * image.scale);
}


static inline CGSize DFSizeScaled(CGSize size, CGFloat scale) {
   return CGSizeMake(size.width * scale, size.height * scale);
}


static inline CGSize DFRoundedEvenedSize(CGSize size) {
   NSInteger width = size.width;
   if (width % 2 != 0) width += 1;
   NSInteger height = size.height;
   if (height % 2 != 0) height += 1;
   return CGSizeMake(width, height);
}

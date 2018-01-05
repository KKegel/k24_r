# k24_r

k24_r is an image generation algorithm which builds a 8192px^2 bitmap (.bmp) from a random seed.
the generated images are looking expressive abstract but interesting.

the algorithm takes care of
* color distribution
* contrast
* complement colors
* complement proportion
* color excitement
* shading

## build

compile the provided source code and run then ``k24_r /your/file/path/``

note that the program will take around 200MiB RAM and will run several minutes. the output file has around 150MiB

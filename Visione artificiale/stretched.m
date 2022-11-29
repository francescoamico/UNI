function img=stretched(img)
    img = single(rgb2gray(img));
    img = img-min(img(:));
    img = img/max(img(:));
    img = uint8(img*255);
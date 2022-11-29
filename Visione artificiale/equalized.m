function out=equalized(img)
    img = rgb2gray(img);
    h = size(img,1)*size(img,2)/255; % altezza=Area/base
    lut = uint8(cumsum(imhist(img,256))/h);
    out = lut(img+1);
function [dx,dy,mod,dirHSV]=getGradient(img)
    dx = genConv(single(rgb2gray(img)),fspecial('sobel'));
    dy = genConv(single(rgb2gray(img)),fspecial('sobel')');
    mod = sqrt(dx.^2+dy.^2);
    dirHSV = uint8(((atan2(dy,dx)+pi)/(2*pi))*360); % pronta per imshow(dirHSV, hsv(360));
    
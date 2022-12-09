function img=threshold(img)
    med = medfilt2(img,31,31);
    img = rgb2gray(img);
    
    img=img>med;
end
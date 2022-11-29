function [mat1,mat2,n]=uniqueRGB(img)
    if size(img,3) ~= 3
        error('img non é rgb');
    end
    
    imgR = img(:,:,1);
    imgG = img(:,:,2);
    imgB = img(:,:,3);
    
    h = size(img,1);
    w = size(img,2);
    mat1 = zeros(h*w,3,'uint8');
    for i=1:h*w
        mat1(i) = imgR(i);
        mat1(i+h*w) = imgG(i);
        mat1(i+2*h*w) = imgB(i);
    end
    
    mat2 = unique(mat1,'rows');
    n = size(mat2,1);
function [out,map]=grayLevels1530(img)
    out = img(:,:,1)*0.212671+img(:,:,2)*0.715160+img(:,:,3)*0.072169;
    
    R = [0 0 0 floor((6:1523)/6) 254 254 254 254 254 255 255 255 255];
    G = [floor((0:1523)/6) 254 254 254 254 255 255];
    B = zeros(size(G,2),1,'uint8');
    ind = (1:3:1524);
    B(ind) = G(ind);
    B(ind+1) = G(ind+1)+1;
    B(ind+2) = G(ind+2)+2;
    B(1525:end)=[254 255 254 255 254 255];
    
    map = zeros(1530,3,'uint8');
    map(1:1530) = R;
    map(1531:3060) = G;
    map(3061:end) = B;
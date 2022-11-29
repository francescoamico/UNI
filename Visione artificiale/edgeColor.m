function out=edgeColor(img)
    
    [dx,dy,mod,dirHSV]=getGradient(img);
    colorMap = [[0 0 0 ];hsv(360)];
    dirHSV = dirHSV+1; 
    edg = uint8(edge(rgb2gray(img),"Sobel"));
    out = ind2rgb(dirHSV.*edg,colorMap);


    

    
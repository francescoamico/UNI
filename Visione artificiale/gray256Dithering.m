function out=gray256Dithering(img,N)
    % da 256 a N livelli di grigio
    seq = round(0:255/(N-1):255); 
    seq=seq(floor((0:255)/(256/N))+1);
    out=seq(img+1);
    
    %dithering
    [h,w]=size(img);
    for i=1:h
        for j=1:w
            error=img(i,j)-out(i,j);
            if j<w
                out(i,j+1)=out(i,j+1)+error*7/16;
            end
            if i<h
                out(i+1,j)=out(i+1,j)+error*5/16;
            end
            if i<h && j>1
                out(i+1,j-1)=out(i+1,j-1)+error*3/16;
            end
            if i<h && j<h
                out(i+1,j+1)=out(i+1,j+1)+error*1/16;
            end
        end
    end





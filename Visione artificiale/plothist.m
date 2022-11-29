function h=plothist(img)
    h=imhist(uint8(img),256)';
    m=101-ceil(100*double(h)/double(max(h(:)))); % normalizzo e trovo la riga di partenza tra 1 e 100
    out=zeros(120,256,'uint8')+255;
    for i=1:256
        out(m(i):100,i)=0;
        out(102:120,i)=i-1;
    end
    figure; imshow(out);
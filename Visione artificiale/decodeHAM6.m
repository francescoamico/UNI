function img=decodeHAM6(file,h,w)
    [map16,values] = read(file,h,w); % restituisce la mappa e i valori(control,data) di ogni pixel 

    % decodifico l'immagine
    imgR = zeros(w,h,'uint8');
    imgG = zeros(w,h,'uint8');
    imgB = zeros(w,h,'uint8');
    k=1;
    for i=1:h*w
        control=values(k);
        data=values(k+1);
        k=k+2;
        switch control
            case 0
                lastpx=[map16(data+1,1) map16(data+1,2) map16(data+1,3)];  % gli indici delle matrici partono da 1
            case 16
                lastpx(1)=data*17;
            case 32
                lastpx(2)=data*17; 
            case 48
                lastpx(3)=data*17;
        end
        imgR(i)=lastpx(1);
        imgG(i)=lastpx(2);
        imgB(i)=lastpx(3);
    end
    img(:,:,1) = imgR';
    img(:,:,2) = imgG';
    img(:,:,3) = imgB';
    

function [map16,values]=read(file,h,w)
    fileID = fopen(file,'r');
    content = fread(fileID);
    
    % leggo la mappa primi 4*48=92bit
    k=1;
    map16=zeros(3,16,'uint8');
    for i=1:2:48
        map16(i)=bitshift(content(k),-4,'uint8')*17;
        map16(i+1)=bitand(content(k),15)*17;
        k=k+1;
    end
    map16=map16';

    % leggo control e data di ogni bit
    values = zeros(1,h*w*2,'uint8'); % due valori (control,data) per ogni pixel
    controlMask = 192; % 11000000
    dataMask = 240; % 11110000
    len = 8;
    for i=1:2:h*w*2
        if len==0
            k=k+1;
            len=8;
        end
        values(i)=bitshift(bitand(content(k),controlMask),-2,'uint8');
        content(k)=bitshift(content(k),2,'uint8');
        len=len-2;
        if len==0
            k=k+1;
            len=8;
        end
        if len==2
            k=k+1;
            a=bitshift(bitand(content(k),controlMask),-2,'uint8');
            values(i+1)=bitshift(bitor(content(k-1),a),-4,'uint8');
            content(k)=bitshift(content(k),2,'uint8');
            len=6;
        else
            values(i+1)=bitshift(bitand(content(k),dataMask),-4,'uint8');
            content(k)=bitshift(content(k),4,'uint8');
            len=len-4;
        end
    end
    fclose(fileID);

  
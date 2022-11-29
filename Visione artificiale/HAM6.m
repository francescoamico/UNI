function filename=HAM6(img)
    rgb4096 = pagetranspose(round(img/17)); % in passato si lavorava con immagini a 4096 colori 12bpp
    [ind16, map16] = rgb2ind(rgb4096*17, 16);
    map16 = round(map16*15); % prendo i 16 colori della mappa da un range di 4096 valori e non 2^24 
    rgb16 = double(ind2rgb(ind16,map16));
    rgb4096 = double(rgb4096);

    r16 = rgb16(:,:,1); g16 = rgb16(:,:,2); b16 = rgb16(:,:,3);
    r4096 = rgb4096(:,:,1); g4096 = rgb4096(:,:,2); b4096 = rgb4096(:,:,3);

    distance = sqrt(sum((rgb4096-rgb16).^2,3));

    global v  k l buffersize
    buffersize=1024; % 1 KB
    k=1; v=zeros(1,buffersize,'uint8'); l=8;
    filename='HAM6.bin';
    fileID = fopen(filename,'w'); 
    
    %carico su file la colorMap 
    map16=map16';
    for i=1:48 
         write(fileID,map16(i),4);% per scrivere 4 bpp
    end

    write(fileID,ind16(1),6); % carico primo pixel control=00 data=ind16(1) 6 bpp
    lastpx = rgb16(1,1,:);
    for i=2:size(img,1)*size(img,2)
        % hold green and blue modify red
        dr=sqrt(sum(([lastpx(2) lastpx(3)]-[g4096(i) b4096(i)]).^2));     
        % hold red and blue modify green
        dg=sqrt(sum(([lastpx(1) lastpx(3)]-[r4096(i) b4096(i)]).^2));
        % hold red and green modify blue
        db=sqrt(sum(([lastpx(1) lastpx(2)]-[r4096(i) g4096(i)]).^2));
        
        [~,choice] = min([distance(i) dr dg db]);
        switch choice
            case 1
                write(fileID,ind16(i),6);
                lastpx = [r16(i) g16(i) b16(i)];
            case 2
                write(fileID,16+r4096(i),6);
                lastpx(1) = r4096(i);
            case 3
                write(fileID,32+g4096(i),6);
                lastpx(2) = g4096(i);
            case 4
                write(fileID,48+b4096(i),6);
                lastpx(3) = b4096(i);
        end
    end
    fwrite(fileID,v(v~=0)); % flush del buffer
    fclose(fileID);
    
function write(fileID,n,j) 
    global v  k  l buffersize
    l=l-j;
    v(k)=v(k)+bitshift(n,l,'uint8'); 
    if k==buffersize && l<=0 
        fwrite(fileID,v);
        k=0; 
        v=zeros(1,buffersize,'uint8'); 
    end
    if l==0 
        k=k+1;
        l=8;
    end
    if l<0 
        k=k+1;
        l=l+8; 
        v(k)=v(k)+bitshift(n,l,'uint8');  
    end

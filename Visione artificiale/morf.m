function out=morf(img,se,flag) % flag=0 erosione, flag~=0 dilatazione
    if flag == 0
        op = @(x) min(x);
        val=255; % permette di ignorare i risultati fuori dall'immagine
    else
        op = @(x) max(x);
        val=0;
    end

    [he,we]=size(se);
    % trovo le cordinate del centro dell'elemento strutturante
    i=round(he/2); 
    j=round(we/2);
    left=j-1; % padding sx
    right=we-j; % padding dx
    up=i-1; % padding up
    bottom=he-i; % padding bottom
    
    % raggiro il problema ai bordi immergendo l'immagine in una più grande
    tmp=ones(size(img),'uint8');
    tmp=padarray(tmp,[bottom,right],val,'post');
    tmp=padarray(tmp,[up,left],val,'pre');
    out=tmp;

    range=find(tmp); % trovo l'area interessata
    tmp(range)=img; % copio l'immagine dentro l'area
    
    [ise,jse]=find(se); % trovo gli indici degli 1 nell'elemento strutturante
    lut=(j-jse)*size(tmp,1)+(i-ise); % per accedere velocemente ai livelli di grigio dei pixel individuati da SE

    for k=range'
        out(k)=op(tmp(k+lut));
    end

    out=uint8(out(up+1:end-bottom,left+1:end-right));

 % apertura = dilatazione_(erosione) _ = flip SE
 % chiusura = erosione_(dilatazione)
 % ro = dilatazione - erosione   con raggio di SE piccolo(se disco raggio1)
 % th = im-apertura
 % bh = chiusura-im
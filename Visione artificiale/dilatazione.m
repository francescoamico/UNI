function out=dilatazione(img,se,centro)
    % out=dilatazione(zelda,disco(5),[2 2])
    % out=dilatazione(zelda,disco(5)) il centro viene calcolato dalla funzione
    % figure; imshow(out,[])
    arguments
        img
        se
        centro (1,2) = round(size(se)/2) % coordinate del centro dell'elemento strutturante di default
    end
    i=centro(1);
    j=centro(2);
  
    [he,we]=size(se);
    left=j-1; % padding sx
    right=we-j; % padding dx
    up=i-1; % padding up
    bottom=he-i; % padding bottom
    
    % raggiro il problema ai bordi immergendo l'immagine in una più grande
    tmp=ones(size(img),'uint8');
    tmp=padarray(tmp,[bottom,right],0,'post');
    tmp=padarray(tmp,[up,left],0,'pre');
    out=tmp;

    range=find(tmp); % trovo l'area interessata
    tmp(range)=img; % copio l'immagine dentro l'area
    
   [ise,jse]=find(se); % trovo gli indici degli 1 nell'elemento strutturante
   lut=(j-jse)*size(tmp,1)+(i-ise); % per accedere velocemente ai livelli di grigio dei pixel individuati da SE

    for k=range'
        out(k)=max(tmp(k+lut));
    end

    out=out(up+1:end-bottom,left+1:end-right);
    
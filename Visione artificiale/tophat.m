function out=tophat(img,se,centro)
    % out=tophat(zelda,disco(5),[2 2])
    % out=tophat(zelda,disco(5)) il centro viene calcolato dalla funzione
    % figure; imshow(out,[])
    arguments
        img
        se
        centro (1,2) = round(size(se)/2) % coordinate del centro dell'elemento strutturante di default
    end
    out = img-apertura(img,se,centro);
    
    
function out=k(img,se,centro)
    % out=k(zelda,disco(5),[2 2])
    % out=k(zelda,disco(5)) il centro viene calcolato dalla funzione
    % figure; imshow(out,[])
    arguments
        img
        se
        centro (1,2) = round(size(se)/2) % coordinate del centro dell'elemento strutturante di default
    end
    out = single(img)+single(tophat(img,se,centro))-single(bottomhat(img,se,centro));
    out = uint8(max(0,min(255,out)));
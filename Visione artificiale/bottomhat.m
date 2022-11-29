function out=bottomhat(img,se,centro)
    % out=bottomhat(zelda,disco(5),[2 2])
    % out=bottomhat(zelda,disco(5)) il centro viene calcolato dalla funzione
    % figure; imshow(out,[])
    arguments
        img
        se
        centro (1,2) = round(size(se)/2) % coordinate del centro dell'elemento strutturante di default
    end
    out = chiusura(img,se,centro)-img;
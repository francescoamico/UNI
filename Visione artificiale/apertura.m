function out=apertura(img,se,centro)
    % out=apertura(zelda,disco(5),[2 2])
    % out=apertura(zelda,disco(5)) il centro viene calcolato dalla funzione
    % figure; imshow(out,[])
    arguments
        img
        se
        centro (1,2) = round(size(se)/2) % coordinate del centro dell'elemento strutturante di default
    end
    out = erosione(img,se,centro);
    % ribalto in orizzontale e in verticale l'elemento strutturante
    out = dilatazione(out,rot90(se,2),centro);
    
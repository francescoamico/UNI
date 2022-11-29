function out=chiusura(img,se,centro)
    % out=chiusura(zelda,disco(5),[2 2])
    % out=chiusura(zelda,disco(5)) il centro viene calcolato dalla funzione
    % figure; imshow(out,[])
    arguments
        img
        se
        centro (1,2) = round(size(se)/2) % coordinate del centro dell'elemento strutturante di default
    end
    out = dilatazione(img,se,centro);
    % ribalto in orizzontale e in verticale l'elemento strutturante
    out = erosione(out,rot90(se,2),centro);
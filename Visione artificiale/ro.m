function out=ro(img)
    % out=ro(img)
    % figure; imshow(out,[])
    out = dilatazione(img,disco(1))-erosione(img,disco(1));
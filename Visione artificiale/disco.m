function se=disco(r)
    se = zeros(r+r+1,'uint8');
    rr = r^2;
    for y=-r:r
        for x=-r:r
            if x^2+y^2 <= rr
                se(x+r+1,y+r+1) = 1;
            end
        end
    end
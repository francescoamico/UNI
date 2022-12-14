function C=DCT(f)
    N = size(f,2);
    alpha(1:N) = sqrt(2/N); alpha(1) = sqrt(1/N);
    ker = cos(((2*(0:N-1)+1)*pi/(2*N))'*(0:N-1));
    C = alpha.*(f*ker);



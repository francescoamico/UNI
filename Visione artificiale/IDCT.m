function f=IDCT(C)
    N = size(C,2);
    alpha(1:N) = sqrt(2/N); alpha(1) = sqrt(1/N);
    ker = cos(((0:N-1)*pi/(2*N))'*(2*(0:N-1)+1));
    f = (alpha.*C)*ker;
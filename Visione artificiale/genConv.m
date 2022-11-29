function out=genConv(img,ker)
    ker = rot90(ker,2); % ribaltamento kernel orizz e vert

    [hk,wk]=size(ker);
    i=round(hk/2); % trovo le cordinate del centro del kernel
    j=round(wk/2);
    left=j-1; % padding sx
    right=wk-j; % padding dx
    up=i-1; % padding up
    bottom=hk-i; % padding bottom
    
    tmp=ones(size(img),'single');
    tmp=padarray(tmp,[bottom,right],0,'post');
    tmp=padarray(tmp,[up,left],0,'pre');
    out=tmp;
    
    range=find(tmp);
    tmp(range)=img;

    h=size(tmp,1);
    lut=zeros(hk,wk);
    for l=1:hk
        for k=1:wk
            lut(l,k)= (k-j)*h+(l-i);
        end
    end
    lut=lut(1:hk*wk);
    
    ker=(0:255)'*ker(:)'; % "mappa" ci permette di risparmiare molt.
    for i=range'
        t=0;
        for k=1:hk*wk
            t=t+ker(tmp(i+lut(k))+1,k);
        end
        out(i)=t;
    end
   
    out=uint8(out(up+1:end-bottom,left+1:end-right));
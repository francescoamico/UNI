function out=rot(img,alpha)
    [h,w]=size(img);
    alpha=(alpha/180)*pi;

    xp(1)=cos(alpha)-sin(alpha);
    xp(2)=w*cos(alpha)-sin(alpha);
    xp(3)=cos(alpha)-h*sin(alpha);
    xp(4)=w*cos(alpha)-h*sin(alpha);
    W=round(max(xp)-min(xp));
    
    yp(1)=sin(alpha)+cos(alpha); 
    yp(2)=w*sin(alpha)+cos(alpha); 
    yp(3)=sin(alpha)+h*cos(alpha); 
    yp(4)=w*sin(alpha)+h*cos(alpha);
    H=round(max(yp)-min(yp));
    
    disp(H)
    disp(W)
    out=zeros(W,H,'uint8');
    Hm=round(H/2);
    Wm=round(W/2);

    for i=-Hm:Hm
     for j=-Wm:Wm
         x=round(j*cos(alpha)+i*sin(alpha)+w/2+1);
         y=round(i*cos(alpha)-j*sin(alpha)+h/2+1);
         if y>0 && y<=h && x>0 && x<=w 
            out(j+Wm+1,i+Hm+1)=img(x,y);
         end
     end
    end
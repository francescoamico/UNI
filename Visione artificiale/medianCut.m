function [indexed,map]=medianCut(img, n)
    lvl = log2(n);
    if floor(lvl) ~= lvl
		error('Number of colours must be power of 2');
    end
    
    [colours,cube,number] = uniqueRGB(img); % cube=colori rgb senza ripetizione
    if number < n
		error('Number of colours especified is greater than number of colours of the image');
    end
    
    global colorMap indexedImage 
    colorMap = []; indexedImage=zeros(size(img,1),size(img,2),'uint8');
    mc(img,colours,double(cube),lvl);
    map = colorMap;
    indexed = indexedImage;


function mc(img,colours,cube,lvl)
    global colorMap
    if lvl == 0
        [h,w] = size(cube);
        centroid = zeros(1,3,'double');
        freq = zeros(1,h);
        for i=1:h
            freq(i) = nnz(all(colours==cube(i,1:w),2));
            centroid = centroid+freq(i)*cube(i,1:w);
        end
        colorMap = [colorMap;(centroid/sum(freq))/255];
        indexedImage(img,cube,size(colorMap,1)-1);
        return;
    end
    [cube,median] = findMedian(cube);
    cube1 = cube(1:median,:);
    cube2 = cube(median+1:end,:);
    mc(img,colours,cube1,lvl-1);
    mc(img,colours,cube2,lvl-1);
   

function [cube,median]=findMedian(cube)
    [~,axis] = max(max(cube)-min(cube));
    cube = sortrows(cube,axis);
    tot = round(sum(cube(:,axis))/2);
    running_sum = 0;
    median = 0;
    while median < size(cube,1) && running_sum < tot
        median = median+1;
        running_sum = running_sum+cube(median,axis);
    end
   
    
function indexedImage(img,cube,value)
    global indexedImage
    redChannel = img(:, :, 1);
    greenChannel = img(:, :, 2);
    blueChannel = img(:, :, 3);
    for i=1:size(cube,1)
        pos = find(redChannel == cube(i,1) & greenChannel == cube(i,2) & blueChannel == cube(i,3));
        indexedImage(pos') = value;
    end
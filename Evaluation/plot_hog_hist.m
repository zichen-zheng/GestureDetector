%   Written by    Zichen Zheng
%   Created on    Dec 6, 2013
%
%   Copyright (c) 2013 Zichen Zheng. All rights reserved.

close all;
clear all;

set(0,'DefaultAxesFontSize',15);

figure;
img = imread('sample.png');
h = HOG(img);
h = h(1:9);
bar(h);
title('Histogram of Orientation of a Cell');
%axis([0.5 9.5 0 0.8]);
set(gca, 'XTickLabel', {'10','30','50','70','90','110','130','150','170'});
set(gca, 'YTickLabel', []);
export_fig hog-histogram.eps -transparent;
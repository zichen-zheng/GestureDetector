%PLOT_DATA is a MATLAB script to plot evaluation data of GestureDetector.

%   Written by    Zichen Zheng
%   Created on    Dec 6, 2013
%
%   Copyright (c) 2013 Zichen Zheng. All rights reserved.

clear all;
close all;

set(0,'DefaultAxesFontSize',15);

xlsfile = 'evaluation.xls';
sheet = 1;
data = xlsread(xlsfile, sheet);

numUniSamples = 244;
numCompSamples = 194;

%% win size
figure;
result = data(39:46,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'16';'24';'32';'40';'48';'56';'64';'72'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]});
text(x_loc{1}-0.32, acc+1.7, num2str(acc,'%.2f'),'FontSize',12)
xlabel('Side Length of Window', 'fontsize', 18);
ylabel('Accuracy', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
axis([0 9 0 90]);
title('HOG Window Size');
export_fig('Figures/winsize', '-eps', '-transparent');

%% Linear SVM
figure;
result = data(2:7,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'1e-4';'1e-3';'1e-2';'1e-1';'1';'1e1'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]})
text(x_loc{1}-0.2, acc+1.7, num2str(acc,'%.2f'),'FontSize',12)
xlabel('Regulariaztion Term {\itC}', 'fontsize', 18);
ylabel('Accuracy', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
title('Linear SVM');
axis([0 7 0 90]);
export_fig('Figures/linear-c', '-eps', '-transparent');

%% RBF: C
figure;
result = data(9:16,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'1e-4';'1e-3';'1e-2';'1e-1';'1';'1e1';'1e2';'1e3'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]})
text(x_loc{1}-0.3, acc+1.7, num2str(acc,'%.2f'),'FontSize',12)
xlabel('Regulariaztion Term C', 'fontsize', 18);
ylabel('Accuracy', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
title('RBF Kernel SVM (\gamma = 1 / num_features)');
axis([0 9 0 90]);
export_fig('Figures/rbf-c', '-eps', '-transparent');

%% RBF: gamma
figure;
result = data(18:25,4:5);
result(:,1) = result(:,1)*numUniSamples;
result(:,2) = result(:,2)*numCompSamples;
result = result / (numUniSamples+numCompSamples);
y = bar(result, 'stacked');
acc = (result(:,1)+result(:,2));
xname = {'1e-4';'5e-4';'7.5e-4';'1e-3';'2.5e-3';'5e-3';'1e-2';'5e-2'};
x_loc = get(y, 'XData');
y_height = get(y, 'YData');
set(gca, 'xticklabel', xname)
set(y,{'FaceColor'},{[0.2 0.4 0.8];[1 0.85 0]})
text(x_loc{1}-0.3, acc+1.7, num2str(acc,'%.2f'),'FontSize',12)
xlabel('RBF Parameter \gamma', 'fontsize', 18);
ylabel('Accuracy', 'fontsize', 18);
legend('Uniform', 'Complex', 'Location','NorthWest');
title('RBF Kernel SVM ({\itC} = 1)');
axis([0 9 0 95]);
export_fig('Figures/rbf-gamma', '-eps', '-transparent');

%% Trianing Time
figure;
result = data(39:46,1);
plot(result, 'o', 'MarkerSize', 10, 'LineWidth', 2);
title('Training Time Elasped');
xname = {'16';'24';'32';'40';'48';'56';'64';'72'};
set(gca, 'xticklabel', xname)
xlabel('Side Length of Window', 'fontsize', 18);
ylabel('Time (s)', 'fontsize', 18);
hold on;
plot(result, 'LineWidth', 2);
export_fig('Figures/train-time', '-eps', '-transparent');

%% Predicting Time
figure;
result = data(39:46,2);
plot(result, 'ro', 'MarkerSize', 10, 'LineWidth', 2, 'MarkerEdgeColor', [0 0.6 0]);
title('Predicting Time Elasped');
xname = {'16';'24';'32';'40';'48';'56';'64';'72'};
set(gca, 'xticklabel', xname)
xlabel('Side Length of Window', 'fontsize', 18);
ylabel('Time (s)', 'fontsize', 18);
hold on;
plot(result, 'Color', [0 0.6 0], 'LineWidth', 2);
export_fig('Figures/predict-time', '-eps', '-transparent');

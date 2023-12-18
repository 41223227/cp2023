var tipuesearch = {"pages": [{'title': 'About', 'text': '', 'tags': '', 'url': 'About.html'}, {'title': '線上繪圖', 'text': '列印 10 次 Hello World \n', 'tags': '', 'url': '線上繪圖.html'}, {'title': 'w13', 'text': '#include <stdio.h>\n\nint main() {\n// 開啟文件以寫入位移和速度數據\nFILE *outputFile = fopen("motion_data.txt", "w");\nif (!outputFile) {\nfprintf(stderr, "無法創建數據文件。\\n");\nreturn 1;\n}\n\n// 模擬運動 10 秒並計算位移和速度，同時將數據寫入文件\ndouble x = 0.2; // 初始位移\ndouble v = 0.0; // 初始速度\ndouble dt = 0.01; // 時間步長\ndouble t = 0.0; // 時間\n\nwhile (t <= 10.0) {\ndouble acceleration = (-10.0 * x - 0.5 * v) / 1.0; // 這裡修改了系統的參數\nv += acceleration * dt;\nx += v * dt;\n\nfprintf(outputFile, "%lf %lf %lf\\n", t, x, v);\n\nt += dt;\n}\n\n// 關閉數據文件\nfclose(outputFile);\n\n// 使用popen啟動Gnuplot進程\nFILE *gnuplotPipe = popen("gnuplot -persistent", "w");\nif (!gnuplotPipe) {\nfprintf(stderr, "無法啟動Gnuplot。\\n");\nreturn 1;\n}\n\n// 使用Gnuplot繪圖指令，指定字型文件和輸出PNG\nfprintf(gnuplotPipe, "set terminal png font \'default,12\' size 800,400\\n");\nfprintf(gnuplotPipe, "set output \'./../images/motion_plot.png\'\\n");\nfprintf(gnuplotPipe, "set title \'displacement and velocity vs. time\'\\n");\nfprintf(gnuplotPipe, "set xlabel \'time (s)\'\\n");\nfprintf(gnuplotPipe, "set ylabel \'displacement (m)\'\\n");\nfprintf(gnuplotPipe, "plot \'motion_data.txt\' using 1:2 with lines lw 2 title \'displacement\', \\\n\'motion_data.txt\' using 1:3 with lines lw 2 title \'velocity\'\\n");\n\n// 關閉Gnuplot進程\nfprintf(gnuplotPipe, "exit\\n");\npclose(gnuplotPipe);\n\nreturn 0;\n} \n', 'tags': '', 'url': 'w13.html'}, {'title': 'w12', 'text': '\n #include <stdio.h>\n#include <gd.h>\n#include <math.h>\n\nint main() {\nint width = 800;\nint height = 600;\n\ngdImagePtr img = gdImageCreateTrueColor(width, height);\ngdImageAlphaBlending(img, 0);\n\nFILE *outputFile = fopen("hellogd.png", "wb");\nif (outputFile == NULL) {\n\nfprintf(stderr, "Error opening the output file.\\n");\n\nreturn 1;\n}\n\nint red = gdImageColorAllocate(img, 255, 0, 0);\nint blue = gdImageColorAllocate(img, 0, 0, 255);\nint black = gdImageColorAllocate(img, 0, 0, 0);\nint white = gdImageColorAllocate(img, 255, 255, 255);\n// 長方形塗色\ngdImageFilledRectangle(img, 0, 0, width, height, white);\ngdImageFilledRectangle(img, 0, 0, (int)width/4, (int)height/4, blue);\n// 橢圓形塗色\ngdImageFilledEllipse(img, (int)width*3/4, (int)height/4, (int)width/4, (int)width/4, red);\n// 橢圓形畫線\ngdImageEllipse(img, (int)width*3/4, (int)height*3/4, (int)width/4, (int)width/4, red);\n// 畫直線\ngdImageLine(img, (int)width/2, (int)height/2, (int)width/2, (int)height/2 + 100, blue);\n\n// 多邊形畫線\ngdPoint points[4];\npoints[0].x = (int)width/4;\npoints[0].y = (int)height*3/4;\npoints[1].x = points[0].x + 100;\npoints[1].y = points[0].y;\npoints[2].x = points[1].x;\npoints[2].y = points[1].y + 100;\npoints[3].x = points[2].x - 100;\npoints[3].y = points[2].y;\ngdImagePolygon(img, points, 4, black);\n\n// 多邊形塗色\ngdPoint points2[4];\npoints2[0].x = (int)width/3;\npoints2[0].y = (int)height/2;\npoints2[1].x = points2[0].x + 100;\npoints2[1].y = points2[0].y;\npoints2[2].x = points2[1].x;\npoints2[2].y = points2[1].y + 100;\npoints2[3].x = points2[2].x - 150;\npoints2[3].y = points2[2].y;\ngdImageFilledPolygon(img, points2, 4, red);\n\ngdImagePngEx(img, outputFile, 9);\nfclose(outputFile);\ngdImageDestroy(img);\nreturn 0;\n}\n\nclear\ncd downloads\ncc hellogd.c\n./a.out \n', 'tags': '', 'url': 'w12.html'}, {'title': 'w6', 'text': '// https://en.wikipedia.org/wiki/Flag_of_the_United_States\n// https://www.britannica.com/topic/flag-of-the-United-States-of-America\n// 以下為幾乎要繪製完成的美國國旗, 請修改下列原始碼, 令其繪出正確的美國國旗\n#include <stdio.h>\n#include <gd.h>\n#include <math.h>\n\nvoid draw_usa_flag(gdImagePtr img);\nvoid draw_star(gdImagePtr img, int x, int y, int size, int color);\n\nint main() {\n    int width = 800;\n    int height = (int)(width / 1.9);\n\n    gdImagePtr img = gdImageCreateTrueColor(width, height);\n    gdImageAlphaBlending(img, 0);\n\n    draw_usa_flag(img);\n\n    FILE *outputFile = fopen("./../images/usa_flag.png", "wb");\n    if (outputFile == NULL) {\n        fprintf(stderr, "Error opening the output file.\\n");\n        return 1;\n    }\n\n    gdImagePngEx(img, outputFile, 9);\n    fclose(outputFile);\n    gdImageDestroy(img);\n\n    return 0;\n}\n\nvoid draw_usa_flag(gdImagePtr img) {\n    int width = gdImageSX(img);\n    int height = gdImageSY(img);\n    int red, white, blue;\n    // Colors for the flag\n    red = gdImageColorAllocate(img, 178, 34, 52); // Red stripes\n    white = gdImageColorAllocate(img, 255, 255, 255); // White stripes\n    blue = gdImageColorAllocate(img, 60, 59, 110); // Blue field\n\n    int stripe_height = height / 13;\n    int stripe_width = width;\n    int star_size = (int)(0.0308 * height); // Corrected star size (half the original size)\n\n    for (int y = 0; y < height; y += stripe_height) {\n        if (y / stripe_height % 2 == 0) {\n            gdImageFilledRectangle(img, 0, y, stripe_width, y + stripe_height, red);\n        } else {\n            gdImageFilledRectangle(img, 0, y, stripe_width, y + stripe_height, white);\n        }\n    }\n\n    gdImageFilledRectangle(img, 0, 0, width * 2 / 5, stripe_height * 7, blue);\n\n    int star_spacing_x = (int)(0.063 * height); // Horizontal spacing between stars\n    int star_spacing_y = (int)(0.054 * height); // Vertical spacing between stars\n    int star_start_x = (int)(0.0616 * height); // Starting X position for stars\n    int star_start_y = (int)(0.0485 * height); // Starting Y position for stars\n\n    for (int row = 0; row < 9; row++) {\n        int starsPerRow = (row % 2 == 0) ? 6 : 5;\n\n        for (int star = 0; star < starsPerRow; star++) {\n            int x = star_start_x + star * star_spacing_x;\n            int y = star_start_y + row * star_spacing_y;\n            draw_star(img, x, y, star_size, white);\n        }\n    }\n}\n\nvoid draw_star(gdImagePtr img, int x, int y, int size, int color) {\n    gdPoint points[10];\n\n    for (int i = 0; i < 10; i++) {\n        double angle = M_PI / 2 + i * 2 * M_PI / 10;\n        int radius = (i % 2 == 0) ? size : size / 2;\n        points[i].x = x + radius * cos(angle);\n        points[i].y = y + radius * sin(angle);\n    }\n\n    // Fill the star with white color\n    gdImageFilledPolygon(img, points, 10, color);\n}\n\nclear\ncd downloads\ncc gd_usa_flag.c\n./a.out\n \n \n // https://en.wikipedia.org/wiki/Flag_of_the_Republic_of_China\n// cc roc_flag.c -lgd -lm to link with gd and math library\n// https://www.rapidtables.com/web/color/RGB_Color.html\n// 幾何形狀著色與繪圖練習\n// 以下 gd 繪圖程式嘗試畫出 ROC 國旗, 請根據下列程式內容完成後續的國旗繪圖\n#include <stdio.h>\n#include <gd.h>\n#include <math.h>\n\nvoid draw_roc_flag(gdImagePtr img);\nvoid draw_white_sun(gdImagePtr img, int x, int y, int size, int color);\n\nint main() {\n    // width 3: height 2\n    int width = 1200;\n    int height = (int)(width*2.0 / 3.0);\n\n    gdImagePtr img = gdImageCreateTrueColor(width, height);\n    gdImageAlphaBlending(img, 0);\n\n    draw_roc_flag(img);\n\n    FILE *outputFile = fopen("./../images/roc_flag1.png", "wb");\n    if (outputFile == NULL) {\n        fprintf(stderr, "Error opening the output file.\\n");\n        return 1;\n    }\n    gdImagePngEx(img, outputFile, 9);\n    fclose(outputFile);\n    gdImageDestroy(img);\n    return 0;\n}\n\nvoid draw_roc_flag(gdImagePtr img) {\n    int width = gdImageSX(img);\n    int height = gdImageSY(img);\n    int red, white, blue;\n    int center_x = (int)(width/4);\n    int center_y = (int)(height/4);\n    int sun_radius = (int)(width/8);\n    // Colors for the flag\n    red = gdImageColorAllocate(img, 242, 0, 0); // Red color\n    white = gdImageColorAllocate(img, 255, 255, 255); // White stripes\n    blue = gdImageColorAllocate(img, 0, 41, 204); // Blue\n    // red rectangle area\n    gdImageFilledRectangle(img, 0, 0, width, height, red);\n    // blue rectangle area\n    gdImageFilledRectangle(img, 0, 0, (int)(width/2.0), (int)(height/2.0), blue);\n    // 目前僅畫出青天白日的輪廓直線, 請嘗試計算所需的點座標完成國旗繪圖\n    draw_white_sun(img, center_x, center_y, sun_radius, white);\n}\n\nvoid draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {\n    float angle = 0;\n    int fromX, fromY;\n    int toX, toY;\n    for (int i=0; i<24; i++){\n        angle += 5*M_PI*2/12;\n        //printf("%.3f", angle);\n        toX = center_x + cos(angle)*sun_radius;\n        toY = center_y + sin(angle)*sun_radius;\n        // 只有 i 為 0 時移動到 toX, toY, 其餘都進行直線繪圖\n        if (i!=0){\n            gdImageLine(img, fromX, fromY, toX, toY, color);\n        }\n        fromX = toX;\n        fromY = toY;\n   }\n}\n\nclear\ncd downloads\ncc gd_roc_flag.c\n./a.out\n \n \n \n', 'tags': '', 'url': 'w6.html'}, {'title': 'w5', 'text': '// 包含標準輸出入程式庫的標頭文件\n// https://blog.csdn.net/weixin_38468077/article/details/101069365\n// http://www.gnuplot.info/demo/\n// https://github.com/sysprog21/rv32emu\n// https://github.com/sysprog21/semu \n// https://docs.google.com/presentation/d/14N0cWG2SnBSqhc2cLF0_2VerB9FF8JN3\n// https://cs61c.org/fa23/\n// https://greenteapress.com/wp/think-python-2e/\n// https://github.com/ecalvadi/c99-examples\n// https://github.com/gouravthakur39/beginners-C-program-examples\n// https://github.com/ergenekonyigit/Numerical-Analysis-Examples\n// https://www.che.ncku.edu.tw/facultyweb/changct/html/teaching/CPPandMATLAB/Past/pdf%20Files/Chap02-Ling.pdf\n// https://gteceducation.com.sg/Brochures/PROGRAMMING/C%20PROGRAMMING%20FULL.pdf\n// https://jsommers.github.io/cbook/cbook.pdf\n// https://jsommers.github.io/cbook/index.html\n// http://student.itee.uq.edu.au/courses/csse2310/CProgrammingNotes.pdf\n// http://cslibrary.stanford.edu/101/EssentialC.pdf\n// https://publications.gbdirect.co.uk/c_book/\n// https://www.fossil-scm.org/fossil-book/doc/2ndEdition/fossilbook.pdf\n// ***** execute on replit \n// cd downloads\n// cc gnuplot_ex1.c -o gnuplot_ex1\n// ./gnuplot_ex1\n#include <stdio.h>\n\n// 主函式\nint main() {\n    // Start a Gnuplot process using popen\n    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");\n    if (!gnuplotPipe) {\n        fprintf(stderr, "Failed to start Gnuplot.\\n");\n        return 1;\n    }\n\n    // Use Gnuplot plotting commands, specify font and output as PNG\n    fprintf(gnuplotPipe, "set terminal png font \'default,10\' size 800,400\\n");\n    fprintf(gnuplotPipe, "set output \'./../images/gnuplot_ex1.png\'\\n");\n    fprintf(gnuplotPipe, "plot sin(x)");\n    // Close popen\n    pclose(gnuplotPipe);\n\n    return 0;\n}\n\nclear\ncd downloads\ncc gnuplot_ex1.c\n./a.out\n \n', 'tags': '', 'url': 'w5.html'}, {'title': 'Brython', 'text': 'https://en.wikipedia.org/wiki/Python_(programming_language) \n Examples: \n https://gist.github.com/mdecycu/d9082d678096bd58378d6afe2c7fa05d \n https://www.geeksforgeeks.org/python-programming-examples/ \n https://www.programiz.com/python-programming/examples \n https://www.freecodecamp.org/news/python-code-examples-sample-script-coding-tutorial-for-beginners/ \n Python Tutorial: \n https://docs.python.org/3/tutorial/ \n An informal introduction to Python \n Indentation (Python 採 4 個 Spaces 縮排, 以界定執行範圍) \n Variables ( Python Keywords ) \n Comments (# 單行註解, 三個單引號或三個雙引號標註多行註解) \n Numbers  (整數 int(), 浮點數 float()) \n Strings  (字串) \n print (Python 內建函式,  print()  函式) \n Python control flow tools \n for \n if \n range \n open \n read \n lists \n tuples \n dictionaries \n functions \n try ... except \n break \n pass \n classes \n 這個頁面 demo 如何在同一頁面下納入多個線上 Ace 編輯器與執行按鈕 ( practice_html.txt  動態頁面超文件). \n practice_html.txt  動態頁面超文件應該可以在啟動 Brython 時, 設定將 .py 檔案放入 downloads/py 目錄中引用. \n 亦即將所有對應的 html 也使用 Brython 產生, 然後寫為  class  後, 在範例導入時透過  instance  引用. \n <!-- 啟動 Brython -->\n<script>\nwindow.onload=function(){\nbrython({debug:1, pythonpath:[\'./../cmsimde/static/\',\'./../downloads/py/\']});\n}\n</script> \n 從 1 累加到 100: \n 1 add to 100 \n 將 iterable 與 iterator  相關說明 , 利用 Brython 與 Ace Editor 整理在這個頁面. \n  導入 brython 程式庫  \n \n \n \n \n  啟動 Brython  \n \n \n \n  導入 FileSaver 與 filereader  \n \n \n \n \n  導入 ace  \n \n \n \n \n \n \n  導入 gearUtils-0.9.js Cango 齒輪繪圖程式庫  \n \n \n \n \n \n \n  請注意, 這裡使用 Javascript 將 localStorage["kw_py_src1"] 中存在近端瀏覽器的程式碼, 由使用者決定存檔名稱 \n \n \n \n \n \n \n  add 1 to 100 開始  \n \n \n  add 1 to 100 結束 \n  editor1 開始  \n  用來顯示程式碼的 editor 區域  \n \n  以下的表單與按鈕與前面的 Javascript doSave 函式以及 FileSaver.min.js 互相配合  \n  存擋表單開始  \n Filename:  .py   \n  存擋表單結束  \n \n  執行與清除按鈕開始  \n Run   Output   清除輸出區 清除繪圖區 Reload \n  執行與清除按鈕結束  \n \n  程式執行 ouput 區  \n \n  Brython 程式執行的結果, 都以 brython_div1 作為切入位置  \n \n  editor1 結束   ##########################################  \n 從 1 累加到 100 part2: \n 1 add to 100 cango_three_gears BSnake AI Tetris Rotating Block \n  請注意, 這裡使用 Javascript 將 localStorage["kw_py_src2"] 中存在近端瀏覽器的程式碼, 由使用者決定存檔名稱 \n \n \n \n  add 1 to 100 part2 開始  \n \n \n  add 1 to 100 part2 結束 \n  editor2 開始  \n  用來顯示程式碼的 editor 區域  \n \n  以下的表單與按鈕與前面的 Javascript doSave 函式以及 FileSaver.min.js 互相配合  \n  存擋表單開始  \n Filename:  .py   \n  存擋表單結束  \n \n  執行與清除按鈕開始  \n Run   Output   清除輸出區 清除繪圖區 Reload \n  執行與清除按鈕結束  \n \n  程式執行 ouput 區  \n \n  Brython 程式執行的結果, 都以 brython_div1 作為切入位置  \n \n  editor2 結束  \n \n \n', 'tags': '', 'url': 'Brython.html'}]};
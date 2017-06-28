import my_module as mm
import time as t
from threading import Thread

N = int(10e8)
t1 = t.time();
th1 = Thread(target=mm.count_custom, args=(N//2, ))
th2 = Thread(target=mm.count_custom, args=(N//2, ))
th1.start()
th2.start()
th1.join()
th2.join()
print 'Two threads: ', t.time() - t1
t1 = t.time();
mm.count_custom(N)
print 'single thread: ', t.time() - t1

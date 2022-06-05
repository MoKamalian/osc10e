/*
 *
 * Author: amir kamalian
 * Date:   05-June-2022
 * Description: 
 *
 * 
 * 
 */


 import java.util.List;


public class Priority implements Algorithm {
    
    private List<Task> queue;

    public Priority(List<Task> queue) {
        this.queue = queue;
    }


    public void schedule() {
        /* sort the queue based on highest to lowest priority and execute 
           the processes */
        pickNextTask();
        for(Task task : queue) {
            CPU.run(task, task.getBurst());
        }
    }

    /* sort the queue array from highest priority to lowest priority */
    public Task pickNextTask() {
        
        Task temp;
        for(int i=0; i<queue.size(); i++) {

            for(int j=i+1; j<queue.size(); j++) {

                if(queue.get(i).getPriority() > queue.get(j).getPriority()) {

                    temp = queue.get(i);
                    queue.set(i, queue.get(j));
                    queue.set(j, temp);

                }

            }

        }

        return queue.get(0);
    }


    
}

/*
 *
 * Author: amir kamalian
 * Date: 10-June-2022
 * Description: Priority RR scheduler.  This is non-preemptive 
 * 
 * 
 */


import java.util.List;


public class PriorityRR implements Algorithm {
 

    private List<Task> queue;


    public PriorityRR(List<Task> queue) {
        this.queue = queue; 
    }


    public void schedule() {

        pickNextTask();
        for(Task task : queue) {
            CPU.run(task, task.getBurst());
        }

    }


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

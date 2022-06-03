/*
 *
 * author: Amir Kamalian
 * date:   02-May-2022
 * description: shortest job first algorithm
 * 
 * 
 */

import java.util.List;


public class SJF implements Algorithm {

    private List<Task> queueToSchedule; 

    public SJF(List<Task> queue) {
        this.queueToSchedule = queue;
    }


    public void schedule() {
        /* run task and remove said taks once done running */
        pickNextTask();
        for(Task task : queueToSchedule) {
            CPU.run(task, task.getBurst());
        }

    }

    /* pick the process with the shortest CPU burst */
    public Task pickNextTask() {
        
        Task task;
        for(int i=0; i<queueToSchedule.size(); i++) {

            for(int j=i+1; j<queueToSchedule.size(); j++) {

                if(queueToSchedule.get(i).getBurst() > queueToSchedule.get(j).getBurst()) {

                    task = queueToSchedule.get(i);
                    queueToSchedule.set(i, queueToSchedule.get(j));
                    queueToSchedule.set(j, task);

                }

            }

        }
        
        return queueToSchedule.get(0);
    }




}




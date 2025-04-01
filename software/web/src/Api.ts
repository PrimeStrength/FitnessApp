import { setTimeout } from "node:timers/promises"
import { WorkoutData } from "./FitnessTypes"
import { makeObserver, Subscriber } from "./Publisher"

export type Api = {
    storeWorkoutData: (data: WorkoutData) => void

    addWorkoutDataSub: (sub: Subscriber<WorkoutData[]>) => void
    removeWorkoutDataSub: (sub: Subscriber<WorkoutData[]>) => void
}

export const makeLocalStorageApi = (): Api => {
    const storage =
        window.localStorage;

    const initialWorkoutData: WorkoutData[] = (() => {
        const existingDataStr = storage.getItem("workoutData");
        if (!existingDataStr) {
            return []
        } else {
            return JSON.parse(existingDataStr);
        }
    })()

    const workoutDataObs = makeObserver<WorkoutData[]>(initialWorkoutData);

    const storeWorkoutData = (workoutData: WorkoutData) => {
        console.log(workoutData)
        const existingDataStr = storage.getItem("workoutData");
        if (!existingDataStr) {
            const newData = [workoutData];
            storage.setItem("workoutData", JSON.stringify(newData));
            workoutDataObs.setValue(newData)
        } else {
            const existingData: WorkoutData[] = JSON.parse(existingDataStr);
            const newData = [...existingData, workoutData];
            storage.setItem("workoutData", JSON.stringify(newData));
            workoutDataObs.setValue(newData)
        }
    }

    const addWorkoutDataSub =
        (sub: Subscriber<WorkoutData[]>) => workoutDataObs.addSub(sub);

    const removeWorkoutDataSub =
        (sub: Subscriber<WorkoutData[]>) => workoutDataObs.removeSub(sub);

    return {
        storeWorkoutData, addWorkoutDataSub, removeWorkoutDataSub
    }
}

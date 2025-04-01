import { RefObject, useEffect, useState } from "react"
import { AppState } from "../State"
import { WorkoutData } from "../FitnessTypes";
import { Api } from "../Api";
import { setTimeout } from "node:timers/promises";


interface IRecordPreviousWorkoutForm {
    api: RefObject<Api>
}

function RecordPreviousWorkoutForm(props: IRecordPreviousWorkoutForm) {
    const { api } = props;
    const [workoutName, setWorkoutName] = useState<string | null>(null);
    const [workoutTimestamp, setWorkoutTimestamp] = useState<number | null>(null);

    const handleNameChange = (event: React.ChangeEvent<HTMLInputElement>) =>
        setWorkoutName(event.target.value);

    const handleDateChange = (event: React.ChangeEvent<HTMLInputElement>) => {
        const timestamp = new Date(event.target.value).getTime();
        setWorkoutTimestamp(timestamp);
    }

    const onSubmit = () => {
      console.log(workoutName, workoutTimestamp)
        if (workoutName !== null && workoutTimestamp !== null) {
            const data: WorkoutData = {
                workoutName: workoutName,
                workoutTimestampMs: workoutTimestamp
            }
            api.current.storeWorkoutData(data)
        }
    }

    return (
        <form
            onSubmit={event => event.preventDefault()}
        >
            <label className="block text-gray-700 font-semibold mb-2" htmlFor="workoutName">
                Workout Name
            </label>
            <input
                type="text"
                id="workoutName"
                className="w-full p-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500"
                placeholder="Enter workout name"
                onChange={handleNameChange}
            />


            <label className="block text-gray-700 font-semibold mt-4 mb-2" htmlFor="workoutDate">
                Workout Date
            </label>
            <input
                type="date"
                id="workoutDate"
                className="w-full p-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500"
                onChange={handleDateChange}
            />

            <div className="mt-4 flex justify-between items-center">
                <button
                    className="px-4 py-2 bg-blue-500 text-white rounded-lg hover:bg-blue-600"
                    onClick={onSubmit}
                >
                    Submit
                </button>

                <button
                    className="px-4 py-2 bg-gray-100 rounded-lg border-solid"
                >
                    reset
                </button>
            </div>
        </form>
    )
}

interface IPreviousWorkoutsProps {
    api: RefObject<Api>
}

function PreviousWorkouts(props: IPreviousWorkoutsProps) {
    const { api } = props;
    const [workoutData, setWorkoutData] = useState<WorkoutData[]>([])

    useEffect(() => {
        const subscriber =
            setWorkoutData;

        api.current.addWorkoutDataSub(subscriber);
        return () => api.current.removeWorkoutDataSub(subscriber);
    }, [])

    return (

        <div className="max-w-sm mx-auto bg-white shadow-lg rounded-2xl overflow-hidden p-6">
            <h2 className="text-xl font-semibold text-gray-800">
                Previous Workouts
            </h2>
            <table>
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Date</th>
                    </tr>
                </thead>

                <tbody>
                    {workoutData.map((workout, idx) => <tr key={"workout idx " + idx}>
                        <td>{workout.workoutName}</td>
                                                         <td>{new Date(workout.workoutTimestampMs).toISOString().split('T')[0]}</td>
                    </tr>)}
                </tbody>
            </table>
        </div>

    )

}

export interface IDashboardProps {
    appState: AppState
    api: RefObject<Api>

}
export function Dashboard(props: IDashboardProps) {
    const { api } = props
    return (
        <div className="grid grid-cols-3 grid-rows-3 gap-4">
            <div className="max-w-sm mx-auto bg-white shadow-lg rounded-2xl overflow-hidden p-6">
                <h2 className="text-xl font-semibold text-gray-800">
                    Record Previous Workout
                </h2>
                <RecordPreviousWorkoutForm api={api} />
            </div>
            <PreviousWorkouts api={api} />
        </div>
    )
}

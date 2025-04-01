import { RefObject, useRef, useState } from 'react'
import Header from './Header'
import { AppState, initialAppState } from './State'
import { Page } from './Pages';
import { Dashboard } from './Pages/Dashboard';
import { Api, makeLocalStorageApi } from './Api';

interface IAppBody {
  apiRef: RefObject<Api>
}

function AppBody(props: IAppBody) {
    const [appState, setAppState] = useState<AppState>(initialAppState);
    const activePage = (() => {
        switch (appState.selectedPage) {
            case Page.Dashboard: return <Dashboard appState={appState} api={props.apiRef} />
            default: return <div />
        }
    })()


    return (
        <div className="h-screen w-full bg-gray-200">
            <Header
                selectedPage={appState.selectedPage}
                changePage={(page: Page) => setAppState({ ...appState, selectedPage: page })}
            />
            {activePage}
        </div>
    )
}

function App() {
    const apiRef = useRef<Api>(makeLocalStorageApi());
    return <AppBody apiRef={apiRef} />

}

export default App

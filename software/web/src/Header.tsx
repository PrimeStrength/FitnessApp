import { Page, pageName, pages } from "./Pages";

interface IHeaderButtonProps {
    name: string,
    onClick: () => void
    selected: boolean
}

const selectedClassName =
    "rounded-md bg-gray-900 px-3 py-2 text-sm font-medium text-white"

const unSelectedClassName =
    "rounded-md px-3 py-2 text-sm font-medium text-gray-300 hover:bg-gray-700 hover:text-white"

function HeaderButton(props: IHeaderButtonProps) {
    const { name, onClick, selected } = props;
    return (
        <div
            className={selected ? selectedClassName : unSelectedClassName}
            onClick={onClick}
        >
            {name}
        </div>
    )
}


interface IHeaderProps {
    changePage: (page: Page) => void
    selectedPage: Page
}

function Header(props: IHeaderProps) {
    const { changePage, selectedPage } = props;
    return (
        <nav className="bg-gray-800">
            <div className="mx-auto max-w-7xl px-2 sm:px-6 lg:px-8">
                <div className="relative flex h-16 items-center justify-between">
                    <div className="flex flex-1 items-center justify-center sm:items-stretch sm:justify-start">
                        <div className="flex shrink-0 items-center">
                            <img className="h-8 w-auto" src="/dumb-bell.svg" alt="Your Company" />
                        </div>
                        <div className="hidden sm:ml-6 sm:block">
                            <div className="flex space-x-4">
                                {pages.map(page => <HeaderButton
                                    key={"hdr-btn-" + pageName(page)}
                                    name={pageName(page)}
                                    onClick={() => changePage(page)}
                                    selected={selectedPage == page}
                                />)}
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </nav >
    )
}

export default Header

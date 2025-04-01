export type Subscriber<a> = (_: a) => void

export type Observer<a> = {
    addSub: (sub: Subscriber<a>) => void
    removeSub: (sub: Subscriber<a>) => void
    notify: () => void
    setValue: (a: a) => void
}

export const makeObserver = <a>(init: a): Observer<a> => {
    let subs = new Set<Subscriber<a>>();

    let value =
        init;

    const addSub = (sub: Subscriber<a>) => {
        subs.add(sub);
        sub(value);
    }

    const removeSub = (sub: Subscriber<a>) =>
        subs.delete(sub);

    const notify = () => {
        subs.forEach(sub => sub(value));
    }

    const setValue = (val: a) => {
        value = val;
        notify();
    }

    return {
        addSub, removeSub, notify, setValue
    }
}

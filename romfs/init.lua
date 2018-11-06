function onInit()
    --
    --  See `main.c` for how and when this function is called.
    --
    io.write("Inside init.lua's onInit(): \n")
    local msg = luainterop(42, 43)
    io.write(msg)

    lua001(21, 21)
    local mystr = lua002()
    local itema, itemb = lua003()

    io.write("mystr = " .. mystr .. "\n")
    io.write("a = " .. itema .. ", b = " .. itemb .. "\n")
end

function onUpdate()
    --
    --  See `main.c` for how and when this function is called.
    --
end

function onEnd()
    --
    --  See `main.c` for how and when this function is called.
    --
end
function file_exists(filename)
    local f = io.open(filename, "rb")
    if f then f:close() end
    return f ~= nil
end

function lines_from(filename)
    if not file_exists(filename) then return {} end
    lines = {}
    for line in io.lines(filename) do
        lines[#lines+1] = line
    end
    return lines
end

function main()
    local input = lines_from("../../input/2021/input1.txt")
    -- print(input[1])
    
    for i=1,#input do
        -- print(input[i])
        input[i] = tonumber(input[i])
    end

    increases = 0
    for i=1,#input-3 do
        prev_window = input[i] + input[i+1] + input[i+2]
        cur_window = input[i+1] + input[i+2] + input[i+3]
        if(cur_window - prev_window > 0) then
            increases = increases + 1
        end
    end

    print(increases)
end

main()
local Players = game:GetService("Players")
local CoreGui = game:GetService("CoreGui")
local TweenService = game:GetService("TweenService")
local LocalPlayer = Players.LocalPlayer

local VALID_KEYS = {
    ["H-65981-K"] = true,
    ["H-42753-S"] = true 
}

local SCRIPT_URL = "https://raw.githubusercontent.com/xqmt/hooksense-loader/refs/heads/main/Idk-bruh"
local SAVE_FILE_NAME = "hooksenseKeySaved.txt"

local TARGET_FONT = Enum.Font.Arcade
local TARGET_TEXT_SIZE = 10

local function LoadMainScript()
    local success, err = pcall(function()
        loadstring(game:HttpGet(SCRIPT_URL))()
    end)
    if not success then
        warn("Script Load Error: " .. tostring(err))
    end
end

if isfile and readfile and isfile(SAVE_FILE_NAME) then
    local savedKey = readfile(SAVE_FILE_NAME)
    if VALID_KEYS[savedKey] then
        LoadMainScript()
        return
    end
end

local function GetHWID()
    local hwid = "UNKNOWN"
    pcall(function()
        if gethwid then
            hwid = gethwid()
        else
            hwid = game:GetService("RbxAnalyticsService"):GetClientId()
        end
    end)
    return hwid
end

local ClientHWID = GetHWID()
local RegisteredHWID = "" 

local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name = "SkeetKeySystem"
ScreenGui.Parent = (gethui and gethui()) or CoreGui
ScreenGui.ResetOnSpawn = false

local MainFrame = Instance.new("Frame")
MainFrame.Name = "MainFrame"
MainFrame.Size = UDim2.new(0, 360, 0, 160)
MainFrame.Position = UDim2.new(0.5, -180, 0.5, -80)
MainFrame.BackgroundColor3 = Color3.fromRGB(5, 5, 5)
MainFrame.BorderColor3 = Color3.fromRGB(0, 0, 0)
MainFrame.BorderSizePixel = 1
MainFrame.Active = true
MainFrame.Draggable = true
MainFrame.Parent = ScreenGui

local AccentBar = Instance.new("Frame")
AccentBar.Name = "AccentBar"
AccentBar.Size = UDim2.new(1, 0, 0, 3)
AccentBar.Position = UDim2.new(0, 0, 0, 0)
AccentBar.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
AccentBar.BorderSizePixel = 0
AccentBar.Parent = MainFrame

local AccentGradient = Instance.new("UIGradient")
AccentGradient.Color = ColorSequence.new({
    ColorSequenceKeypoint.new(0.00, Color3.fromRGB(0, 51, 182)),
    ColorSequenceKeypoint.new(0.50, Color3.fromRGB(0, 195, 255)),
    ColorSequenceKeypoint.new(1.00, Color3.fromRGB(255, 255, 255))
})
AccentGradient.Parent = AccentBar

local TopBar = Instance.new("Frame")
TopBar.Size = UDim2.new(1, 0, 0, 25)
TopBar.Position = UDim2.new(0, 0, 0, 3)
TopBar.BackgroundColor3 = Color3.fromRGB(5, 5, 5)
TopBar.BorderColor3 = Color3.fromRGB(40, 40, 40)
TopBar.BorderSizePixel = 1
TopBar.Parent = MainFrame

local Title = Instance.new("TextLabel")
Title.Size = UDim2.new(1, -10, 1, 0)
Title.Position = UDim2.new(0, 8, 0, 0)
Title.BackgroundTransparency = 1
Title.Text = "hooksense.loader"
Title.TextColor3 = Color3.fromRGB(220, 220, 220)
Title.TextSize = TARGET_TEXT_SIZE
Title.Font = TARGET_FONT
Title.TextXAlignment = Enum.TextXAlignment.Left
Title.Parent = TopBar

local InfoLabel = Instance.new("TextLabel")
InfoLabel.Size = UDim2.new(1, -20, 0, 20)
InfoLabel.Position = UDim2.new(0, 10, 0, 35)
InfoLabel.BackgroundTransparency = 1
InfoLabel.Text = "Enter your key to access"
InfoLabel.TextColor3 = Color3.fromRGB(150, 150, 150)
InfoLabel.TextSize = TARGET_TEXT_SIZE
InfoLabel.Font = TARGET_FONT
InfoLabel.TextXAlignment = Enum.TextXAlignment.Left
InfoLabel.Parent = MainFrame

local KeyInput = Instance.new("TextBox")
KeyInput.Size = UDim2.new(1, -20, 0, 30)
KeyInput.Position = UDim2.new(0, 10, 0, 60)
KeyInput.BackgroundColor3 = Color3.fromRGB(5, 5, 5)
KeyInput.BorderColor3 = Color3.fromRGB(45, 45, 45)
KeyInput.BorderSizePixel = 1
KeyInput.Text = ""
KeyInput.PlaceholderText = "Paste Key Here..."
KeyInput.PlaceholderColor3 = Color3.fromRGB(51, 51, 51)
KeyInput.TextColor3 = Color3.fromRGB(255, 255, 255)
KeyInput.TextSize = TARGET_TEXT_SIZE
KeyInput.Font = TARGET_FONT
KeyInput.ClearTextOnFocus = false
KeyInput.Parent = MainFrame

local StatusLabel = Instance.new("TextLabel")
StatusLabel.Size = UDim2.new(1, -20, 0, 20)
StatusLabel.Position = UDim2.new(0, 10, 0, 95)
StatusLabel.BackgroundTransparency = 1
StatusLabel.Text = "Status: Awaiting Key..."
StatusLabel.TextColor3 = Color3.fromRGB(180, 180, 180)
StatusLabel.TextSize = TARGET_TEXT_SIZE
StatusLabel.Font = TARGET_FONT
StatusLabel.TextXAlignment = Enum.TextXAlignment.Left
StatusLabel.Parent = MainFrame

local SubmitBtn = Instance.new("TextButton")
SubmitBtn.Size = UDim2.new(1, -20, 0, 25)
SubmitBtn.Position = UDim2.new(0, 10, 0, 122)
SubmitBtn.BackgroundColor3 = Color3.fromRGB(6, 6, 6)
SubmitBtn.BorderColor3 = Color3.fromRGB(45, 45, 45)
SubmitBtn.BorderSizePixel = 1
SubmitBtn.Text = "CHECK KEY"
SubmitBtn.TextColor3 = Color3.fromRGB(255, 255, 255)
SubmitBtn.TextSize = TARGET_TEXT_SIZE
SubmitBtn.Font = TARGET_FONT
SubmitBtn.Parent = MainFrame

SubmitBtn.MouseButton1Click:Connect(function()
    local InputtedKey = KeyInput.Text

    if not VALID_KEYS[InputtedKey] then
        StatusLabel.Text = "Status: Invalid Key!"
        StatusLabel.TextColor3 = Color3.fromRGB(255, 75, 75)
        return
    end

    if RegisteredHWID == "" then
        RegisteredHWID = ClientHWID
    end

    if ClientHWID ~= RegisteredHWID then
        StatusLabel.Text = "Status: HWID Mismatch!"
        StatusLabel.TextColor3 = Color3.fromRGB(255, 75, 75)
        return
    end

    if writefile then
        pcall(function()
            writefile(SAVE_FILE_NAME, InputtedKey)
        end)
    end

    StatusLabel.Text = "Status: Success! Loading Script..."
    StatusLabel.TextColor3 = Color3.fromRGB(167, 218, 97)

    task.wait(1)
    ScreenGui:Destroy()
    LoadMainScript()
end)
